import logo from '../assets/logo.svg'
function Logo({size}){
    let prop = 0
    switch(size){
        case "sm": prop = 10;break
        case "md":prop = 20;break
        case "xl":prop = 30;break
    }
    return(
        <div className={`w-${prop} h-${prop}`}>
            <img src={logo} alt="Logo"/>
        </div>
    );
}

export {Logo};