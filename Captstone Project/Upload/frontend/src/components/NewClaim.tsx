import {SdfButton, SdfCurrencyInput, SdfDatePicker, SdfDatePickerV2, SdfFocusPane, SdfInput, SdfSelectSimple, SdfTextarea, } from '@waypoint/react-components';
import { useState } from 'react';
import FileUploadAndReview from './FileUpload.tsx';
import axios, { AxiosError, AxiosResponse } from "axios";
import { useUser } from './UserState.tsx';
import { FileMetadata } from '../types.ts';
import InlineError from './InlineError.tsx';
import { useNavigate } from 'react-router';


function NewClaim() {

    const navigate = useNavigate()
    const { userDetails } = useUser();
    const [visibility, setVisibility] = useState(false)
    // const [files, setFiles] = useState([]);
    const [filesUploader, setFilesUploader] = useState([]);
    const [isRequestCompleted, setIsRequestCompleted] = useState(false);
    const [successResponse, setSuccessResponse] = useState(null);
    const [errorResponse, setErrorResponse] = useState<string | null>(null);

    let fileData: FormData = new FormData();
    filesUploader.forEach((file, index) => {
        fileData.append(`file`, file);
    });

    const initialFormData = {
        employee_id: userDetails.currentUser.id,
        expense_type: "",
        date_of_expense: new Date().toISOString(),
        from_location: "",
        to_location: "",
        travel_type: null,
        amount: null,
        additional_comments: "",
    }

    const [formData, setformData] = useState({
        employee_id: userDetails.currentUser.id,
        expense_type: "",
        date_of_expense: new Date().toISOString(),
        from_location: "",
        to_location: "",
        travel_type: null,
        amount: null,
        additional_comments: "",
    });

    const [errors, setErrors] = useState({
        expense_type: "",
        date_of_expense: "",
        from_location: "",
        to_location: "",
        travel_type: null,
        amount: null,
        file: null,
        additional_comments: "",
    });

    const expense_type = {
        1: "RELOCATION",
        2: "FLIGHT",
        3: "WIFI",
        4: "MOBILE_BILL",
        5: "OUTING"
    }

    const travel_type = {
        1: "INTERCITY_WITH_FAMILY",
        2: "INTERCITY_WITHOUT_FAMILY",
        3: "INTRACITY_WITH_FAMILY",
        4: "INTRACITY_WITHOUT_FAMILY"
    }

    const items = [
        { 'label': 'RELOCATION', 'value': 1 },
        { 'label': 'FLIGHT', 'value': 2 },
        { 'label': 'WIFI', 'value': 3 },
        { 'label': 'MOBILE BILL', 'value': 4 },
        { 'label': 'OUTING', 'value': 5 }
    ]

    const items1 = [
        { 'label': 'INTERCITY WITH FAMILY', 'value': 1 },
        { 'label': 'INTERCITY WITHOUT FAMILY', 'value': 2 },
        { 'label': 'INTRACITY WITH FAMILY', 'value': 3 },
        { 'label': 'INTRACITY WITHOUT FAMILY', 'value': 4 }
    ]
    
    const containerStyle = {
        display: 'grid',
        gap: '1rem',
    };

    const rowStyle = {
        display: 'grid',
        gridTemplateColumns: 'repeat(auto-fit, minmax(25px, 1fr))',
        gap: '1rem',
    };

    const colStyle = {
        display: 'flex',
        flexDirection: 'column',
    };
    
    const handleButtonClick = () => {
        setVisibility(true)
    }

    const handleDismiss = (e: CustomEvent<void>) => {
        setformData(initialFormData)
        fileData = new FormData()
        setFilesUploader([])
        // setFiles([])
        setVisibility(false)
    }

    // function handleMultipleChange(event) {
    //     setFiles([...event.target.files]);
    // }

    const handleErrorDismiss = (e: CustomEvent<void>) => {
        setErrorResponse(null);
    }

    const handleSuccessAccept = (e: CustomEvent<void>) => {
        navigate("/login", {replace:true})
    }

    // const handleRemove = (fileToRemove) => {
    //     setFilesUploader((prevFiles) => prevFiles.filter((file) => file !== fileToRemove));
    //     setFilesUploader(filesUploader.filter((item) => item !== fileToRemove))
    // };

    let newErrors = { ...errors };
    const validateField = (name, value) => {
        switch (name) {
            case "expense_type":
                newErrors.expense_type = value ? null : "Expense type is required.";
                break;

            case "travel_type":
                if (["1", "2", "5"].includes(formData.expense_type)) {
                    newErrors.travel_type = value ? null : "Travel type is required.";
                }
                break;

            case "from_location":
            case "to_location":
                if (["RELOCATION", "FLIGHT", "OUTING"].includes(formData.expense_type)) {
                    newErrors[name] = value ? null : `${name === "from_location" ? "From location" : "To location"} is required.`;
                }
                break;

            case "date_of_expense":
                newErrors.date_of_expense = value ? "" : "Date of expense is required.";
                break;

            case "amount":
                newErrors.amount = value && !isNaN(value) ? null : "Amount must be a valid number.";
                break;

            default:
                break;
        }
        setErrors(newErrors);
        return newErrors[name] === "";
    };
    
    const onChangeexpense_type = (e) => {
        setformData({ ...formData, [e.target.name]: expense_type[e.target.value.value] })
        validateField(e.target.name, e.target.value.value)
    };
    const onChangetravel_type = (e) => {
        setformData({ ...formData, [e.target.name]: travel_type[e.target.value.value] })
        validateField(e.target.name, e.target.value.value)
    };
    const onChangeAmount = (e) => {
        setformData({ ...formData, amount: e.target.value })
        validateField(e.target.name, e.target.value)
    };
    const onChangedate_of_expense = (e) => {
        setformData({ ...formData, date_of_expense: e.target.value })
        validateField(e.target.name, e.target.value)
    };
    const onChangeadditional_comments = (e) => {
        setformData({ ...formData, additional_comments: e.target.value })
        validateField(e.target.name, e.target.value)
    };
    const onChangefrom_location = (e) => {
        setformData({ ...formData, from_location: e.target.value })
        validateField(e.target.name, e.target.value)
    };
    const onChangeto_location = (e) => {
        setformData({ ...formData, to_location: e.target.value })
        validateField(e.target.name, e.target.value)
    };
   

    const handleAccept = async (e) => {
        e.preventDefault();
        let isValid = true;
        Object.keys(formData).forEach((key) => {
            const valid = validateField(key, formData[key]);
            if (!valid) isValid = false;
        });
        let hasError = false;
        if (!hasError) {
            await axios.post("http://localhost:6769/api/expense/add", formData, {
                withCredentials: true
            }).then((response: AxiosResponse) => {
                setIsRequestCompleted(true);
                if (response.status === 201) {
                    if (fileData.has("file")) {

                        axios.post(`http://localhost:6769/api/expense/expense-id/${response.data.id}/upload`, fileData, {
                            withCredentials: true,
                            headers: { "Content-Type": "multipart/form-data" }
                        }).then((fileResponse: AxiosResponse<FileMetadata>) => {
                            if (fileResponse.status) {
                                setSuccessResponse("Expense Successfully Created with the Files!")
                            }
                            else {
                                setErrorResponse("Something went wrong")
                            }
                        }).catch((error: AxiosError) => {
                            setErrorResponse("Something went wrong while uploading file")
                        });
                    } else {
                        setSuccessResponse("Expense Successfully Created!")
                        // navigate("/login", { replace: true })
                    }
                } else {
                    setErrorResponse("Something went wrong while uploading your files. But your expense has been created... :)")
                }
            }).catch((error: AxiosError) => {
                if (error.status) { setErrorResponse("Something went wrong in the backend") }
            });
            setIsRequestCompleted(true);
        }       
    };
    const currDate = new Date();

    return (
        <div>
            <div><span>{errorResponse}</span></div>
            <section className="flex items-center justify-center h-full">
                <SdfButton id="focus-pane-demo-open-button" onClick={handleButtonClick} emphasis='primary'>Start New Claim</SdfButton>
                <SdfFocusPane
                    size="lg"
                    dismiss-label="Cancel"
                    accept-label="Submit"
                    closeable=""
                    spacing="loose"
                    heading="Start a new claim"
                    id="demo-component"
                    status="success"
                    visible={visibility}
                    onSdfAccept={handleAccept}
                    onSdfDismiss={handleDismiss}
                >
                    <div className='flex space-x-20'>
                        <div className="flex flex-col p-4 w-80">
                            <div>
                                <div style={rowStyle}>
                                    <SdfSelectSimple id="expense_type" label="Expense Type" portal-enabled filterable="" items={items} onSdfChange={onChangeexpense_type} name="expense_type" required-state="required"></SdfSelectSimple>
                                </div>
                                {errors.expense_type && <InlineError message={errors.expense_type} />}
                                <br></br>
                                {(formData.expense_type == "RELOCATION") && (
                                    <div style={rowStyle}>
                                        <SdfSelectSimple id="travel_type" label="Travel Type" portal-enabled filterable="" items={items1} onSdfChange={onChangetravel_type} name="travel_type" required-state="required"></SdfSelectSimple>
                                        {errors.travel_type && <InlineError message={errors.travel_type} />}
                                    </div>
                                )}

                                {(formData.expense_type == "RELOCATION" || formData.expense_type == "FLIGHT") && (
                                    // <div className='flex flex-col'>
                                    <>
                                        <div style={rowStyle}>
                                            <div style={colStyle}>
                                                <SdfInput
                                                    label="From Location"
                                                    id="from_location"
                                                    type="text"
                                                    required-state="required"
                                                    onSdfInput={onChangefrom_location}
                                                    value={formData.from_location}
                                                />
                                                {/* {errors.from_location && <p className="text-red-500">{errors.from_location}</p>} */}
                                                {errors.from_location && <InlineError message={errors.from_location} />}
                                            </div>
                                            <div style={colStyle}>
                                                <SdfInput
                                                    label="To Location"
                                                    id="to_location"
                                                    type="text"
                                                    required-state="required"
                                                    onSdfInput={onChangeto_location}
                                                    value={formData.to_location}
                                                />
                                                {errors.to_location && <InlineError message={errors.to_location} />}
                                            </div>
                                        </div>
                                    </>
                                )} 
                                <div>
                                    <div className="flex flex-col">
                                        <SdfDatePickerV2 label="Date of Expense" id="date_of_expense" portal-enabled="" required-state="required" onSdfChange={onChangedate_of_expense} value={formData.date_of_expense}></SdfDatePickerV2>
                                        {errors.date_of_expense && <InlineError message={errors.date_of_expense} />}
                                    </div>
                                    <br></br>
                                    <div style={rowStyle}>
                                        <SdfCurrencyInput label="Amount" placeholder="Amount" id="amount" type="text" required-state="required" currency-code="INR" onSdfInput={(e) => onChangeAmount(e)} ></SdfCurrencyInput>
                                    </div>
                                    {errors.amount && <InlineError message={errors.amount} />}
                                </div>
                                <br></br>
                                <div className="flex flex-col items-right justify-right ">
                                    <SdfTextarea rows={5} resize="none" label="Additional Comments" id="additional_comments" onSdfChange={onChangeadditional_comments} ></SdfTextarea>
                                </div>
                            </div>
                        </div>
                        <div>
                            <FileUploadAndReview filesUploader={filesUploader} setFilesUploader={setFilesUploader}>
                            </FileUploadAndReview>
                        </div>
                    </div>
                    <SdfFocusPane
                        size="sm"
                        dismiss-label="Try Again?"
                        accept-label="Home"
                        closeable=""
                        spacing="normal"
                        heading="Error"
                        id="demo-component"
                        status="error"
                        visible={(errorResponse !== null)}
                        onSdfAccept={handleSuccessAccept}
                        onSdfDismiss={handleErrorDismiss} >
                        <h3>{errorResponse}</h3>
                    </SdfFocusPane>
                    <SdfFocusPane
                        size="sm"
                        accept-label="Okay"
                        spacing="normal"
                        heading="Success"
                        status="success"
                        hide-dismiss-button=""
                        visible={(successResponse !== null)}
                        onSdfAccept={handleSuccessAccept}>
                        <h3>{successResponse}</h3>
                    </SdfFocusPane>
                    {filesUploader.length > 0 && (
                        <div style={{ marginTop: "20px" }} className='w-full'>
                            <h3>Files Preview:</h3>
                            {filesUploader.map((file, index) => (
                                <div key={index} style={{ marginBottom: "10px", borderBottom: "1px solid #ccc" }}>
                                    <p>
                                        <strong>Filename:</strong> {file.name} (<strong>Type:</strong> {file.type})
                                    </p>
                                    {file.type.startsWith("image/") && (
                                        <img
                                            src={URL.createObjectURL(file)}
                                            alt="Preview"
                                            style={{ width: "100%", marginTop: "10px" }}
                                        />
                                    )}
                                    {file.type === "application/pdf" && (
                                        <embed
                                            src={URL.createObjectURL(file)}
                                            type="application/pdf"
                                            style={{ width: "100%", height: "400px", marginTop: "10px" }}
                                        />
                                    )}
                                    {file.type.startsWith("text/") && (
                                        <iframe
                                            src={URL.createObjectURL(file)}
                                            title="Text Preview"
                                            style={{ width: "100%", height: "200px", marginTop: "10px" }}
                                        />
                                    )}
                                    {["application/vnd.openxmlformats-officedocument.presentationml.presentation", "application/vnd.ms-powerpoint"].includes(file.type) && (
                                        <p>Preview not supported for PowerPoint files</p>
                                    )}
                                    {["application/vnd.openxmlformats-officedocument.spreadsheetml.sheet", "application/vnd.ms-excel"].includes(file.type) && (
                                        <p>Preview not supported for Excel files</p>
                                    )}
                                </div>
                            ))}
                        </div>
                    )}
                </SdfFocusPane>
            </section>
        </div>
    );
}

export default NewClaim;