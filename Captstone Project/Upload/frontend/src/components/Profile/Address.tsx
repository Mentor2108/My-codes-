import { useCallback, useMemo, useState } from 'react';
import { SdfBox, SdfButton, SdfIcon, SdfIconButton, SdfInput, SdfSelectItem, SdfSelectSimple, SdfTextarea } from '@waypoint/react-components';
import { Country, State, City, ICountry, IState, ICity } from 'country-state-city';
import { AddressType, EPerson, IAddress, IPerson, PersonAction } from '../../types.ts';
import InlineError from '../InlineError.tsx';
import AddressComponent from './AddressComponent.tsx';
import { useProfileData } from './reducersWithInitialStates.ts';





function Address(props: {
    state: { input: IPerson, error: EPerson },
    dispatch: React.Dispatch<PersonAction>,
    editable:boolean
}) {
    const { state, dispatch, editable } = props;

    const { profileInitialState } = useProfileData();

    const [edit, setEdit] = useState(false);
  
    const containerStyle = {
        display: 'grid',
        gap: '1rem',
    };

    const rowStyle = {
        display: 'grid',
        gridTemplateColumns: 'repeat(auto-fit, minmax(250px, 1fr))',
        gap: '1rem',
    };

    const colStyle = {
        display: 'flex',
        flexDirection: 'column',
    };


    return (

        <div style={containerStyle}>
            <div className='flex justify-between'>
                <h2 className="text-heading-05 mt-4 mb-4">
                    Address Details
                </h2>
                {editable && <div className='flex items-center'>
                    <SdfIconButton onClick={() => {
                        dispatch({
                            type: 'RESET',
                            payload: { profileInitialState }
                        })
                        setEdit(true)}
                        
                    }>
                        <SdfIcon icon="action-edit" />
                    </SdfIconButton>
                </div>}
            </div>
            

            <AddressComponent addressType={AddressType.CURRENT_ADDRESS} dispatch={dispatch} state={state} editable={editable} edit={edit} setEdit={setEdit}/>
            <AddressComponent addressType={AddressType.PERMANENT_ADDRESS} dispatch={dispatch} state={state} editable={editable} edit={edit} setEdit={setEdit}/>
            
        </div>
    )
}

export { Address };