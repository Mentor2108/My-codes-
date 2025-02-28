package main

import (
	"encoding/json"
	"fmt"
	"net/http"

	"github.com/gorilla/mux"
)

type FlightSchedule struct {
	ID         string
	FlightName string
	Code       int
}

var Flights = map[string]FlightSchedule{
	"123": FlightSchedule{
		ID:         "123",
		FlightName: "Flight#123",
		Code:       101,
	},
	"112": FlightSchedule{
		ID:         "112",
		FlightName: "Flight#112",
		Code:       102,
	},
}

func GetFlightDetail(w http.ResponseWriter, r *http.Request) {
	params := mux.Vars(r)

	id := params["id"]
	// id, err := strconv.Atoi(params["id"])
	// if err != nil {
	//     json.NewEncoder(w).Encode("{\"error\": }")
	// }
	fmt.Printf("requested id:%s\n", id)
	json.NewEncoder(w).Encode(Flights[id])
}

func main() {
	handler := mux.NewRouter()

	handler.HandleFunc("/flight/{id}", GetFlightDetail).Methods("GET")

	http.ListenAndServe(":8080", handler)
}
