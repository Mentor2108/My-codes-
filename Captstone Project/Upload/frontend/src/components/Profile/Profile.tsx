import { SdfBox } from '@waypoint/react-components';
import { Person } from './Personal.tsx';
import { EPerson, IPerson, PersonAction } from '../../types.ts';
import { Address } from './Address.tsx';


function Profile(props: { state: { input: IPerson, error: EPerson }, dispatch: React.Dispatch<PersonAction>, compEditable: boolean }) {
    const { state, dispatch, compEditable } = props;

    return (
        <div>
            <section className="p-10">
                <SdfBox id="demo-component" variant="bordered">
                    {<Person state={state} dispatch={dispatch} editable={compEditable} />}
                </SdfBox>
            </section>

            <section className="p-10">
                <SdfBox id="demo-component" variant="bordered">
                    {<Address state={state} dispatch={dispatch} editable={compEditable} />}
                </SdfBox>
            </section>
        </div>

    );
}

export default Profile;