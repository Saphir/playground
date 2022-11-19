package v1

import (
	"fmt"
)

type Porsche struct {
	Body      string
	Wheel     string
	Door      string
	FrontSeat string
	Gps       string
}

type Bmw struct {
	Body      string
	Wheel     string
	Door      string
	FrontSeat string
	RearSeat  string
}

func Work() {
	porsche := &Porsche{Body: "Porsche Body", Wheel: "Porsche Wheel", Gps: "Porsche Gps", Door: "Porsche Door", FrontSeat: "Porsche FrontSeat"}
	fmt.Println(porsche)

	bmw := &Bmw{Body: "Bmw Body", Wheel: "Bmw Wheel", Door: "Bmw Door", FrontSeat: "Bmw FrontSeat", RearSeat: "Bmw RearSeat"}
	fmt.Println(bmw)
}