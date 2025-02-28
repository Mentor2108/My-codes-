import { useCallback, useEffect, useMemo, useRef, useState } from 'react';
import { ClientSideRowModelModule } from '@ag-grid-community/client-side-row-model';
// Theme
import { ColDef, ICellRendererParams, ModuleRegistry, RowHeightParams, RowValueChangedEvent } from '@ag-grid-community/core';
import { AgGridReact } from '@ag-grid-community/react';
// React Grid Logic
import '@ag-grid-community/styles/ag-grid.css';
// Core CSS
import '@ag-grid-community/styles/ag-theme-quartz.css';
import '../styles.css'
import { Expense, ExpenseStatus, ExpenseType, FileMetadata, LoadingProp, Report } from '../types.ts';
import { SdfBadge, SdfButton, SdfInput, SdfMultiSelect, SdfSelectItem, SdfSelectSimple } from '@waypoint/react-components';
import axios, { AxiosResponse } from 'axios';
import { SetFilterModule } from "@ag-grid-enterprise/set-filter";
import PopulateUserDetails from '../services/populateUserDetails.ts';
import { useUser } from './UserState.tsx';
import { GetExpenseTypeFromEnum } from '../services/enumToDiplayText.ts';
import ErrorBanner from './ErrorBanner.tsx';
import { Spacing } from './Spacing.tsx';
ModuleRegistry.registerModules([ClientSideRowModelModule, SetFilterModule]);

function ExpenseTypeRenderer(params: ICellRendererParams<Expense>) {
    const expenseType = GetExpenseTypeFromEnum(params.value)
    return <div className='flex items-center h-full'>
        {expenseType}
    </div>
}

function StatusRenderer(params: ICellRendererParams<Expense>) {
    let status: JSX.Element

    switch (params.data.expense_status) {
        case ExpenseStatus.APPROVED:
            status = <SdfBadge status="new">Approved</SdfBadge>;
            break;
        case ExpenseStatus.WAITING_FOR_APPROVAL:
            status = <SdfBadge status="changed">Pending</SdfBadge>;
            break;
        case ExpenseStatus.PAID:
            status = <SdfBadge status="complete">Paid</SdfBadge>;
            break;
        case ExpenseStatus.REJECTED:
            status = <SdfBadge status="failed">Rejected</SdfBadge>;
            break;
    }
    return <div className='flex items-center justify-center h-full'>
        {status}
    </div>
}

function FileNameDisplayComponent(params: ICellRendererParams<Expense>) {
    return <div className='flex justify-center'>
        <div>
            {params.data.file.map(file => {
                return (<div><SdfButton className="flex" emphasis="tertiary" onClick={() => handleOpenPdf(params.data.id, file)}>{file.file_name}</SdfButton></div>)
            })}
        </div>
    </div>
}

const Reports = (props: { reports: Expense[], height: number, isSummary: boolean, isPersonalDashboard: boolean, loading: boolean, setLoading: LoadingProp }) => {
    const gridRef = useRef<AgGridReact>(null);
    const { reports, height, isSummary, isPersonalDashboard, loading } = props;
    const [errorMessage, setErrorMessage] = useState<string | null>(null);
    const [colDefs, setColDefs] = useState<ColDef<Expense>[]>([
        { headerName: 'Employee Name', field: 'employee_name', cellDataType: "string", cellRenderer: params => <div className='flex items-center h-full'>{params.value}</div> },
        { headerName: 'Expense Type', maxWidth: 180, field: 'expense_type', cellDataType: "enum", cellRenderer: ExpenseTypeRenderer },
        { headerName: 'Amount', field: 'amount', cellDataType: "number", cellRenderer: params => <div className='flex justify-center items-center h-full'>{params.value}</div> },
        { headerName: 'Date Of Expense', field: 'date_of_expense', cellDataType: "Date", cellRenderer: params => <div className='flex justify-center items-center h-full'>{params.value}</div> },
        { headerName: 'Files', cellDataType: 'string', cellRenderer: FileNameDisplayComponent, autoHeight: true },
        { headerName: 'Remarks', field: 'remarks', cellRenderer: RemarksInputComponent, suppressKeyboardEvent: () => true, minWidth: 150 },
        { headerName: "Actions", cellRenderer: (params: ICellRendererParams<Expense>) => ActionsComponent(params), minWidth: 250 },
        { headerName: 'Expense Status', field: 'expense_status', cellRenderer: StatusRenderer, filter: "agSetColumnFilter", suppressHeaderFilterButton: true, cellDataType: "enum", sort: "desc" },
    ]);

    const { setUserDetails, updateManagedUsers } = useUser();
    const colors = { pending: "#a7692f", rejected: "#f78c8a", approved: "#d0c3f3", paid: "#78d479" }

    const getRowStyle = (params: any) => {
        let borderColor;
        switch (params.data.expense_status) {
            case ExpenseStatus.APPROVED:
                borderColor = colors.approved;
                break;
            case ExpenseStatus.WAITING_FOR_APPROVAL:
                borderColor = colors.pending;
                break;
            case ExpenseStatus.PAID:
                borderColor = colors.paid;
                break;
            case ExpenseStatus.REJECTED:
                borderColor = colors.rejected;
                break;
        }
        return {
            borderLeft: `5px solid ${borderColor}`,
            // backgroundColor: `${borderColor}`,
            color: "#000",
            marginBottom: '50px',
            // boxShadow: '0px 2px 4px rgba(0,0,0,0.1)'
        }
    }

    const onRowValueChanged = useCallback((event: RowValueChangedEvent) => {
        event.api.flashCells();
    }, []);

    const defaultColDef = useMemo<ColDef>(() => {
        return {
            sortingOrder: ["desc", "asc"],
            headerStyle: { backgroundColor: "#4CAF50", color: "white" },
            flex: 1,
            minWidth: 100,
            enableCellChangeFlash: true
        };
    }, []);
    const autoGroupColumnDef = useMemo<ColDef>(() => {
        return {
            minWidth: 200,
        };
    }, []);

    function ActionsComponent(params: ICellRendererParams<Expense>) {
        if (params.data.expense_status !== ExpenseStatus.WAITING_FOR_APPROVAL)
            return null;

        if (isPersonalDashboard)
            return <div className='flex items-center justify-center space-x-3 h-full'>
                <SdfButton
                    action="destructive"
                    emphasis="secondary"
                    size="md"
                    variant="contained"
                    icon="action-delete"
                    onClick={() => deleteExpense(params)}>
                    Delete
                </SdfButton>
            </div>

        return <div className='flex items-center justify-center space-x-3 h-full'>
            <SdfButton icon="action-confirm" onClick={() => handleAction(ExpenseStatus.APPROVED, params)}>
                Approve
            </SdfButton>
            <SdfButton icon="action-close" action="destructive" onClick={() => handleAction(ExpenseStatus.REJECTED, params)}>
                Reject
            </SdfButton>
        </div>
    }

    const expenseTypes = [
        { 'label': "Pending", 'value': ExpenseStatus.WAITING_FOR_APPROVAL },
        { 'label': 'Paid', 'value': ExpenseStatus.PAID },
        { 'label': "Rejected", 'value': ExpenseStatus.REJECTED },
        { 'label': 'Approved', 'value': ExpenseStatus.APPROVED }
    ]
    const [selectedItems, setSelectedItems] = useState(!isPersonalDashboard ? [{ 'label': "Pending", 'value': ExpenseStatus.WAITING_FOR_APPROVAL }] : expenseTypes)

    const handleExpensesStatusFilter = async (evt: CustomEvent<any>) => {
        setSelectedItems(evt.detail)
        const expenseFilter = gridRef.current.api.getColumnFilterInstance("expense_status");
        if (expenseFilter) {
            (await expenseFilter).setModel({
                values: evt.detail.map(item => item.value)
            })
            gridRef.current.api.onFilterChanged();
        }
    }

    function RemarksInputComponent(params: ICellRendererParams<Expense>, setRemarks: React.Dispatch<React.SetStateAction<string>>) {
        if (params.data.expense_status !== ExpenseStatus.WAITING_FOR_APPROVAL)
            return <div className='flex items-center justify-center h-full'>
                {params.value}
            </div>;

        if (isPersonalDashboard)
            return null

        return <div className='flex items-center justify-center h-full'>
            <SdfInput size={13} placeholder='Remarks...?' onSdfChange={evt => {
                params.data.remarks = evt.target.value;
            }} />
        </div>
    }

    const handleAction = async (status: ExpenseStatus, params: ICellRendererParams<Expense>) => {
        try {
            params.data.expense_status = status;
            const response: AxiosResponse<Expense> = await axios.put("http://localhost:6769/api/expense/update/id/" + params.data.id, params.data, {
                withCredentials: true
            });

            if (response.status === 200) {
                params.api.refreshClientSideRowModel();
                props.setLoading.setLoading(true);
                PopulateUserDetails(loading, props.setLoading, setUserDetails, updateManagedUsers);
            } else {
                setErrorMessage("Something went wrong. Please reload and try again.")
            }
        } catch (error) {
            setErrorMessage("Error while updating expense. Please reload and try again.")
        }
        params.api.resetRowHeights();
        params.api.flashCells();
    }


    const deleteExpense = async (params: ICellRendererParams<Expense>) => {
        try {
            const response: AxiosResponse<Expense> = await axios.delete("http://localhost:6769/api/expense/delete/id/" + params.data.id, {
                withCredentials: true
            });

            if (response.status === 200) {
                params.api.refreshClientSideRowModel();
                props.setLoading.setLoading(true);
                PopulateUserDetails(loading, props.setLoading, setUserDetails, updateManagedUsers);
            } else {
                setErrorMessage("Something went wrong. Please reload and try again.")
            }
        } catch (error) {
            setErrorMessage("Error while deleting expense. Please reload and try again.")
        }
        params.api.resetRowHeights();
        params.api.flashCells();
    }

    return (
        <div
            className="ag-theme-quartz p-6"
            style={{ width: '100%', height: `${height}px` }}
        >
            {!isSummary &&
                <div>
                    <section className="flex h-full p-2">
                        <SdfMultiSelect aria="hidden" id="demo-component" emptySelectionStatusMessage="Please select a Expense Status" placeholder="Select Expense Status" label="Expense Status Filter" portal-enabled filterable="" items={expenseTypes} onSdfChange={handleExpensesStatusFilter} value={selectedItems}></SdfMultiSelect>
                    </section>
                </div>}
            {
                errorMessage && <ErrorBanner message={errorMessage} setMessage={setErrorMessage} />
            }
            <Spacing />
            <AgGridReact
                ref={gridRef}
                rowData={reports}
                columnDefs={colDefs}
                defaultColDef={defaultColDef}
                autoGroupColumnDef={autoGroupColumnDef}
                onRowValueChanged={onRowValueChanged}
                getRowStyle={getRowStyle}
                undoRedoCellEditing={true}
                undoRedoCellEditingLimit={5}
                editType='fullRow'
                domLayout={isSummary ? 'normal' : 'autoHeight'}
                getRowHeight={(params: RowHeightParams<Expense, any>) => {
                    return 55 * (Math.floor(params.data.file.length) / 10 + 1);
                }
                }
                onGridReady={async (e) => {
                    // if (!isSummary) {
                    //     props.setLoading.setLoading(true);
                    //     PopulateUserDetails(loading, props.setLoading, setUserDetails, updateManagedUsers);
                    // }
                    e.api.resetRowHeights();
                    const expenseFilter = gridRef.current.api.getColumnFilterInstance("expense_status");
                    if (expenseFilter) {
                        (await expenseFilter).setModel({
                            values: selectedItems.map(item => item.value)
                        })
                        gridRef.current.api.onFilterChanged();
                    }
                }}
            />
        </div>
    );
};

const handleOpenPdf = (expenseId: string, file: FileMetadata) => {
    const pdfWindow = window.open();

    fetch(`http://localhost:6769/api/expense/expense-id/` + expenseId + `/download/file-id/` + file.id, {
        method: "GET",
        credentials: "include",
    }).then((response) => {
        response.blob().then(blob => {
            const pdfUrl = window.URL.createObjectURL(blob);
            pdfWindow.location.href = pdfUrl;
        })
    }).catch((error) => {
        console.error("Error fetching pdf: ", error);
    })

}

export { Reports }