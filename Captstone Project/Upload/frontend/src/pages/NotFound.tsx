import NotFoundSVG from "../components/NotFoundSVG.tsx";
import { Spacing } from "../components/Spacing.tsx";

export default function NotFound() {
    const css = `
        @import url('https://fonts.googleapis.com/css2?family=Permanent+Marker&family=Fira+Mono:wght@500&display=swap');
        body{
            height: 95vh;
            background: #000000;
            text-align: center;
            color: #E0E0E0;
            font-family: 'Fira Mono', monospace;
        }
        h1{
            font-size: 2.5rem;
            font-family: 'Permanent Marker', cursive;
        }
        div{
            transform-style: preserve-3d;
        }
        svg{
            width: clamp(300px , 70% , 600px);
            height: 500px;
        
        }
        #rocket{
            
            transform: translateY(750px);
        
            animation: launch 2s ease-out forwards;
        }
        
        @keyframes launch {
            from {
                transform: translateY(750px);
            }
            to{
                perspective: 500px;
                transform: translateY(0px); 
            }
        }
        #stars {
            animation: twinkling 2s linear ;
        }
        @keyframes twinkling {
        
            from{
                transform: scale(0);
            }
            to{
                transform: scale(1);
            }
        }
        .text{
            opacity: 0;
            animation:appear 1s ease-in forwards;
            animation-delay: 1.8s;
            color: #E0E0E0;
        }
        @keyframes appear {
            from{
                opacity: 0;
            }
            to{
                opacity: 1;
            }
        }
        a{
            color:#F66947;
            text-decoration: none;
        }`
    return (
        <body>
            <style>
                {css}
            </style>
            <div>
                <NotFoundSVG />
            </div>
            <div className='text'>
                <h1>404 Error</h1>
                <h2>Couldn't launch :(</h2>
                <h3>Page Not Found - lets take you <a href="/login">BACK</a></h3>
            </div>
        </body>

    );
}