const express = require('express');
const app = express();
const path = require('path');
const router = express.Router();

const port = 8080; //GOOGLE CLOUD, TIENE QUE SER EL PUERTO 8080

app.use(express.static('WebApp'));

//Funcion que retorna la página de la aplicación
app.get("/", (req, res) => {
    return res.sendFile(path.join(__dirname + '/WebApp/index.html'));
});

app.get("/report", (req, res) => {
    console.log("Hola!!!");
    return res.sendFile(path.join(__dirname + '/WebApp/report.html'));
});

app.get("/asdfasdf", (req, res) => {
    return res.sendFile(path.join(__dirname + '/WebApp/game.html'));
});

app.get("/message", (req, res) => {
    return res.sendFile(path.join(__dirname + '/WebApp/message.html'));
});

//Iniciar la aplicación
app.listen(port, () => console.log(`Aplicación iniciada en el puerto ${port}...`));