function Typography({className,children, padding}){
    return(
        <h1 className={`${className} p-${padding}`}>
            {children}
        </h1>
    );
}

export {Typography}