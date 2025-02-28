package main

import (
	"fmt"
	"net/http"
	// "github.com/gorilla/mux"
)

func ReturnNigga(w http.ResponseWriter, r *http.Request) {
	fmt.Fprintf(w, "YOU ARE A NIGGA!")
}

func main() {
	// handler := mux.NewRouter()

	http.HandleFunc("/", ReturnNigga) //.Methods("GET")

	// http.HandleFunc("/")

	http.ListenAndServe(":8080", nil)
}
