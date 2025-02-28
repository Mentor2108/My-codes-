function calculateJustification(position){
    switch(position){
        case "center": return "justify-center"
        case "right": return "justify-right"
        default:
    }
}

function Row({children, position="", padding=0,padding_left=0,height="full", columns=0, background=""}){
    let justification = calculateJustification(position);
    return(
        <div className={`flex flex-${columns} items-center ${justification} ps-${padding_left} p-${padding} h-${height} bg-${background}`}>
            {children}
        </div>
    );
}

function Col({children,position="", padding=0,padding_left=0}){
    return(
        <div className={`p-${padding} ps-${padding_left}`}>{children}</div>
    );
}

export {Row,Col};