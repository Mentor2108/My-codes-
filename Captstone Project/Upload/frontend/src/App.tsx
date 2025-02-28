import LoginPage from './pages/LoginPage.tsx';
import Homepage from './pages/Homepage.tsx';
import { BrowserRouter, Navigate, Route, Routes, useNavigate } from 'react-router-dom';
import NotFound from './pages/NotFound.tsx';
import { useUser } from './components/UserState.tsx';
import ValidateUser from './services/UserValidation.tsx';
import { useEffect, useState } from 'react';
import LogoutPage from './pages/Logout.tsx';
import Spinner from './components/Spinner.tsx';

function App() {
    const { userDetails } = useUser();
    const [loading, setLoading] = useState(true);
    ValidateUser({ setLoading })
    if (loading)
        return (<div className='flex items-center justify-center h-screen'><Spinner /></div>);

    return (
        <BrowserRouter>
            <Routes>
                <Route path='/login' element={!userDetails.currentUser ? <LoginPage /> : <Navigate replace to='/home' />} />
                <Route path='/home' element={userDetails.currentUser ? <Homepage /> : <Navigate replace to='/login' />} />
                {/* <Route path='/home' element={<Homepage />} /> */}
                <Route path='/logout' element={userDetails.currentUser ? <LogoutPage /> : <Navigate replace to='/login' />} />
                <Route path='/not-found' element={<NotFound />} />
                <Route path='/' element={<Navigate replace to='/login' />} />
                <Route path='*' element={<Navigate replace to='/not-found' />} />
            </Routes>
        </BrowserRouter>
    );
}

export default App;
