import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App.tsx';
import { UserProvider } from './components/UserState.tsx';

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  // <React.StrictMode>
    <UserProvider>
      <App />
    </UserProvider>
  // </React.StrictMode>
);
