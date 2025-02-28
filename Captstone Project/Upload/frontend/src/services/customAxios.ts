import axios from "axios";

const customAxios = axios.create({
    baseURL: process.env.JAVA_PATH,
    withCredentials: true,
});

