const http = require("http")

// const server = http.createServer((req, res) => {
//     if (req.url === "/") {
//         // res.write( "Yo MOFO!");
//         res.end("Yo MOFO!")
//     }
//     else if (req.url === "/ansh") {
//         res.end(`Ansh likes Raghavi or Nitya ? o.o`)
//     }
    
//     else {
//         res.end(`
//         <h1> Hello Humans </h1>
//         <p>You are at the wrong position.</p>
//         <a href="/"> Go back </a>
//         `)
//     }
// })

const server = http.createServer();

server.on("request", (req, res) => {
    res.end("Hello HOOMANS");
})

server.listen(5000);