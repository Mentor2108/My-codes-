import { SdfActionMenu, SdfBox, SdfButton, SdfDatePicker, SdfFocusPane, SdfInput, SdfMenu, SdfMenuItem, SdfTextarea,} from '@waypoint/react-components';
import { useState } from 'react';
import {Row} from '../layouts/RowColumnLayout.tsx';

function Basic1() {
    const [visibility, setVisibility] = useState(false)
    const handleButtonClick = () => {
        setVisibility(true)
    }
    const handleAccept = (e: CustomEvent<void>) => {
        setVisibility(false)
        e.currentTarget.close()
    }
    const handleDismiss = (e: CustomEvent<void>) => {
        setVisibility(false)
        e.currentTarget.close();
    }
    const [formData, setformData] = useState({
       
        employeeId: "",
        expenseType: "",
        dateofExpense: "",
        fromLocation: "",
        toLocation: "",
        typeOfTravel: "",
        amount: "",
        file: null,
        comments: "",
    });
    const handleSubmit = (e) => {
        e.preventDefault();
    };

    return (

        <div>
            <section className="flex items-center justify-center h-full p-8">
                <SdfButton id="focus-pane-demo-open-button" onClick={handleButtonClick}>edit</SdfButton>
                <SdfFocusPane
                    size="lg"
                    dismiss-label="Cancel"
                    accept-label="Submit"
                    closeable=""
                    spacing="normal"
                    heading="edit"
                    id="demo-component"
                    status="success"
                    visible={visibility}
                    onSdfAccept={handleAccept}
                    onSdfDismiss={handleDismiss}   
                >
                        <div>
                            <Row>
                            <section className="flex items-center justify-center h-full p-15">
                                <SdfInput label="Employee Id" id="demo-component" type="text"></SdfInput>
                            </section>
                            <section className="flex items-right justify-right ">
                                    <SdfInput label="Expense Type" id="demo-component" type="text" className="p-2"></SdfInput>
                                </section>
                                <section className="flex items-right justify-right ">
                                    <SdfInput label="Type of Travel" id="demo-component" type="text" className="p-2"></SdfInput>
                                </section>
                            </Row>
                            <Row>
                                <section className="flex items-left justify-left ">
                                    <SdfInput label="fromLocation" id="demo-component" type="text" className="p-2"></SdfInput>
                                </section>
                                <section className="flex items-right justify-right ">
                                    <SdfInput label="toLocation" id="demo-component" type="text" className="p-2"></SdfInput>
                                </section>
                                <section className="flex items-right justify-right ">
                                     <SdfDatePicker label="Date of Expense" id="demo-component"  portal-enabled=""></SdfDatePicker>
                                </section>
                                <section className="flex items-right justify-right ">
                                    <SdfInput label="amount" id="demo-component" type="text" className="p-2"></SdfInput>
                                </section>
                            </Row>
                        </div>
                </SdfFocusPane>
            </section>
        </div>
    );
}

export default Basic1;