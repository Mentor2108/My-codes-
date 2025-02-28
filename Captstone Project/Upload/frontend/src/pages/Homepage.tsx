import {
    SfcShell,
    SfcShellAppBar,
    SdfPageLayout,
    SfcShellTopNav,
    SdfIconButton,
    SdfAvatar,
    SdfFloatingPane,
    SdfIcon,
    SdfButton,
} from "@waypoint/react-components";

import { useEffect, useReducer, useState } from "react";
import Analytics from "./Insights.tsx";
import { Expense } from '../types.ts'
import Summary from "../components/Summary.tsx";
import { useNavigate } from "react-router-dom";
import { useUser } from "../components/UserState.tsx";
import Profile from "../components/Profile/Profile.tsx";
import { initialPersonError, useProfileData, profileReducer } from "../components/Profile/reducersWithInitialStates.ts";
import PopulateUserDetails from "../services/populateUserDetails.ts";
import Spinner from "../components/Spinner.tsx";
import { GetCurrentEmployeeExpenses, GetManagedEmployeeExpenses } from "../services/homePageKPI.ts";
import { Reports } from "../components/Reports.tsx";

export default function Homepage() {
    const [loading, setLoading] = useState(true);
    const { userDetails, setUserDetails, updateManagedUsers } = useUser()
    useEffect(() => {
        PopulateUserDetails(loading, { setLoading }, setUserDetails, updateManagedUsers);
    }, [])
    const menus = [
        {
            title: "Home",
            icon: "home",
            id: "home",
            hash: "#homepage",
            content: "Hello, Nice to meet you again 👋"
        },
        {
            title: "Insights",
            icon: "ext-mdi-insights",
            id: "insights",
            hash: "#insights",
            content: "Insights"
        },
        {
            title: "Team Dashboard",
            icon: "action-view-reports",
            id: "team-dashboard",
            hash: "#team-dashboard",
            content: "Team Dashboard"
        },
        {
            title: "Personal Dashboard",
            icon: "action-view-reports",
            id: "personal-dashboard",
            hash: "#personal-dashboard",
            content: "Personal Dashboard"
        },
        {
            title: "Profile",
            icon: "pto-personal",
            id: "profile",
            hash: "#settings",
            content: ""
        }
    ]

    const [page, setPage] = useState("home")
    const [activeItem, setActiveItem] = useState(menus[0])
    const navigate = useNavigate();

    const { profileInitialState } = useProfileData();
    const [state, dispatch] = useReducer(profileReducer, { input: profileInitialState, error: initialPersonError });
    function handleNavigate(evt) {
        evt.preventDefault();
        const item = evt.detail;
        setActiveItem(item);
        setPage(item.id.toString())
    }
    function gotoTeamDashboard() {
        setPage("team-dashboard")
        setActiveItem(menus.find((element) => element.id === 'team-dashboard'))
    }
    function gotoPersonalDashboard() {
        setPage("personal-dashboard")
        setActiveItem(menus.find((element) => element.id === 'personal-dashboard'))
    }
    function gotoAnalytics() {
        setPage("insights")
        setActiveItem(menus.find((element) => element.id === 'insights'))
    }
    function gotoProfile() {
        setPage("profile")
        setActiveItem(menus.find((element) => element.id === 'profile'))
    }

    function handleLogout() {
        navigate('/logout')
    }

    if (loading) {
        return (<div className='flex items-center justify-center h-screen'><Spinner /></div>);
    }

    const teamReports: Expense[] = GetManagedEmployeeExpenses();
    const personalReports: Expense[] = GetCurrentEmployeeExpenses();
    return (
        <SfcShell>
            <SfcShellAppBar slot="app-bar" size="small" scheme="light">

                Expense Management System
                <div className="w-full flex items-center justify-center" slot="icons">
                    <SdfIconButton shape="circle" label="User menu" class="inline-flex hydrated" id="user-btn" slot="icons" expanded={true}>
                        <SdfIcon icon="pto-personal" />
                    </SdfIconButton>
                </div>
                <SdfFloatingPane auto-attach="" show-arrow="" class="hydrated anchorable-position-context-element" attachment="bottom-start" close-on-click-outside="" data-popper-placement="left-start" style={{ position: 'absolute', inset: '0px 0px auto auto', margin: '0px', transform: 'translate3d(-72px, 8px, 0px)' }}>
                    <div className="p-4 flex flex-col gap-0 items-center" style={{ minWidth: '15rem' }}>
                        <SdfAvatar size="lg" src="" class="hydrated" shape="circle"></SdfAvatar>
                        <p className="text-heading-05 my-0" id="user-menu-name" style={{ color: '#262321', textTransform: 'capitalize' }}>{userDetails.currentUser.last_name ? userDetails.currentUser.first_name + " " + userDetails.currentUser.last_name : userDetails.currentUser.first_name}</p>
                        <p className="text-heading-03 my-0" id="user-menu-title" style={{ color: '#262321' }}>{userDetails.currentUser.email}</p>
                        <nav className="w-full mt-3" aria-label="My user links">
                            <SdfButton className="p-2 w-full box-border size-sm action-standard emphasis-none hydrated" external="" emphasis="teritiary" action="standard" size="sm" onClick={() => gotoProfile()}>Profile</SdfButton>
                            <SdfButton className="p-2 w-full box-border size-sm action-standard emphasis-none hydrated" external="" emphasis="teritiary" action="standard" size="sm" onClick={() => handleLogout()}>Logout</SdfButton>
                        </nav>
                    </div>
                </SdfFloatingPane>

            </SfcShellAppBar>
            <SfcShellTopNav slot="nav" menuProvider={menus} onSfcNavigate={handleNavigate} activeItem={activeItem} collapsed={true} >

            </SfcShellTopNav>
            <SdfPageLayout>
                {page === "insights" && <Analytics />}
                {page === "home" && <Summary gotoTeamDashboard={gotoTeamDashboard} gotoPersonalDashboard={gotoPersonalDashboard} gotoAnalytics={gotoAnalytics} reports={teamReports} setLoading={{ setLoading }} />}
                {page === "team-dashboard" && <Reports reports={teamReports} height={500} isSummary={false} isPersonalDashboard={false} loading={loading} setLoading={{ setLoading }} />}
                {page === "personal-dashboard" && (<Reports reports={personalReports} height={500} isSummary={false} isPersonalDashboard={true} loading={loading} setLoading={{ setLoading }} />)}
                {page === "profile" && <Profile state={state} dispatch={dispatch} compEditable={true} />}
            </SdfPageLayout>

        </SfcShell>
    );
}