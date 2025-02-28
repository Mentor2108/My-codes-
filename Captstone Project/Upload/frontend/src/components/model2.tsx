import { useState } from 'react';
import {Row} from '../layouts/Layout.tsx'
import { SdfButton, SdfFocusPane } from '@waypoint/react-components';

function Basic2() {
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

    return (
        <div> <section className="flex items-center justify-center h-full p-8">
        <SdfButton id="focus-pane-demo-open-button" onClick={handleButtonClick}>delete</SdfButton>
        <SdfFocusPane
            size="sm"
            dismiss-label="Cancel"
            accept-label="Delete"
            closeable=""
            spacing="normal"
            heading="Delete"
            id="demo-component"
            status="success"
            visible={visibility}
            onSdfAccept={handleAccept}
            onSdfDismiss={handleDismiss}>Delete for sure?
            </SdfFocusPane>
            </section>
        </div>
            
                    
     
                
        ); 
    }            
                export default Basic2;
                    
