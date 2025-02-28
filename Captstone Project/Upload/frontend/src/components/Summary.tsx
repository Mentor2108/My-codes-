import { SdfBox, SdfButton, SdfDataRing, SdfIcon, SdfQuickStat } from "@waypoint/react-components";
import NewClaim from "./NewClaim.tsx";
import { PieChart } from "./PieChart.tsx";
import { Expense, ExpenseStatus, LoadingProp, Report } from "../types.ts";
import { useEffect, useMemo, useState } from "react";
import { Reports } from "./Reports.tsx";
import { useUser } from "./UserState.tsx";
import { FilterExpensesByStatus, GetCurrentEmployeeExpensesByStatus, GetManagedEmployeeExpensesByStatus, GetTotalAmountForExpenses } from "../services/homePageKPI.ts";
type VoidFunction = () => void


export default function Summary(props: { gotoTeamDashboard: VoidFunction, gotoPersonalDashboard: VoidFunction, gotoAnalytics: VoidFunction, reports: Expense[], setLoading: LoadingProp }) {
  const { gotoTeamDashboard, gotoPersonalDashboard, gotoAnalytics, reports, setLoading } = props;
  const [afternoon, setAfternoon] = useState(false)
  const nightImage = "https://images.unsplash.com/photo-1698100838054-78a1175928c0"
  const morningImage = "https://images.unsplash.com/photo-1470252649378-9c29740c9fa8"
  const [day, setDay] = useState(false);
  const { userDetails } = useUser()

  const pendingReports = FilterExpensesByStatus(reports, ExpenseStatus.WAITING_FOR_APPROVAL);

  const ExpensesRequiringApprovalList = GetManagedEmployeeExpensesByStatus(ExpenseStatus.WAITING_FOR_APPROVAL)
  const totalAmountOfExpensesRequiringApproval = GetTotalAmountForExpenses(ExpensesRequiringApprovalList);
  const ExpensesPending = GetCurrentEmployeeExpensesByStatus(ExpenseStatus.WAITING_FOR_APPROVAL)
  const totalAmountOfExpensesPending = GetTotalAmountForExpenses(ExpensesPending);

  useEffect(
    () => {
      const hours = new Date().getHours();
      (hours >= 6 && hours < 12) ? setDay(true) : setDay(false);
      (hours >= 12 && hours < 18) ? setAfternoon(true) : setAfternoon(false)
    }
    , [day, setDay])
  return (
    <div>
      <div
        className="relative bg-cover flex justify-between p-4"
        style={{ backgroundImage: `url(${day ? morningImage : nightImage})` }}
      >
        <SdfBox variant="clear">
          <h1 className="text-heading-07 text-inverse-default" style={{textTransform: 'capitalize'}}>{`Good ${day ? "Morning" : (afternoon ? "Afternoon" : "Evening")}, ${userDetails.currentUser.first_name}`}</h1>
        </SdfBox>
        <div className="flex items-center">
          <NewClaim />
        </div>
      </div>
      <div className="grid grid-cols-1 lg:grid-cols-2 gap-4 p-2">
        <SdfBox className="flex-grow" variant="bordered">
          <h3 className="text-heading-05 m-0 mb-4">Overview</h3>
          <div className="grid grid-cols-2 md:grid-cols-2 gap-4 mb-8">
            <SdfBox className="flex-grow" variant="filled" spacing="loose" style={{backgroundColor:"rgb(245, 242, 255)"}}>
              <SdfQuickStat label="Requests needing your approval" size="" className="lg:text-heading-07 md:text-heading-05">{ExpensesRequiringApprovalList.length}</SdfQuickStat>
            </SdfBox>
            <SdfBox className="flex-grow" variant="filled" spacing="loose" style={{backgroundColor:"rgb(245, 242, 255)"}}>
              <SdfQuickStat label="Expenses waiting to be approved" size="" className="lg:text-heading-07 md:text-heading-05">{ExpensesPending.length}</SdfQuickStat>
            </SdfBox>
          </div>
          <div className="grid grid-cols-2 md:grid-cols-2 gap-4 mb-12">
            <SdfBox className="flex-grow" variant="filled" spacing="loose" style={{backgroundColor:"rgb(245, 242, 255)"}}>
              <SdfQuickStat label="Amount" size="" className="lg:text-heading-07 md:text-heading-05">₹{totalAmountOfExpensesRequiringApproval.toLocaleString("en-IN")}</SdfQuickStat>
            </SdfBox>
            <SdfBox className="flex-grow" variant="filled" spacing="loose" style={{backgroundColor:"rgb(245, 242, 255)"}}>
              <SdfQuickStat label="Amount" size="" className="lg:text-heading-07 md:text-heading-05">₹{totalAmountOfExpensesPending.toLocaleString("en-IN")}</SdfQuickStat>
            </SdfBox>
          </div>
          <div className="flex justify-around items-center">
            <div className="flex justify-center mt-8">
              <SdfButton emphasis="secondary" className="w-48" size="sm" expanded onClick={() => gotoTeamDashboard()}>View Team Expenses</SdfButton>
            </div>
            <div className="flex justify-center mt-8">
              <SdfButton emphasis="secondary" className="w-48" size="sm" expanded onClick={() => gotoPersonalDashboard()}>View Your Expenses</SdfButton>
            </div>
          </div>
        </SdfBox>
        <SdfBox className="flex-grow pb-8" variant="bordered" >
          <h3 className="text-heading-05 m-0 mb-4">Analytics</h3>
          <div className="flex justify-center">
            <PieChart width={350} />
          </div>
          <div className="flex justify-center mt-8">
            <SdfButton emphasis="secondary" className="w-48" size="sm" expanded onClick={() => gotoAnalytics()}>Show more</SdfButton>
          </div>
        </SdfBox>
      </div>
      <div className="p-2">
        <SdfBox variant="bordered">
          <h3 className="text-heading-05 m-0 mb-4">Requests Waiting to be Approved...</h3>
          {pendingReports.length !== 0 ? (<div className="">
            <Reports reports={pendingReports.sort(function (a, b) {
              return new Date(b.date_of_expense).getTime() - new Date(a.date_of_expense).getTime();
            }).slice(0, 5)} height={400} isSummary={true} isPersonalDashboard={false} loading={false} setLoading={setLoading} />
          </div>) :
            <div className="flex items-center justify-center h-full">
              <h1>You're all caught up <SdfIcon icon="alert-success"></SdfIcon></h1>
            </div>
          }
        </SdfBox>
      </div>
    </div>
  );
}