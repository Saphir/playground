package v3

import (
	"fmt"
)

func Work() {
	carFactory, err := getCarFactory("Porsche") ; if err != nil {
		panic(err)
	}

	v, err := carFactory.generateCar("Hans", 330.0); if err != nil {
		panic(err)
	}
	m, err := carFactory.generateManual(); if err != nil {
		panic(err)
	}

	fmt.Println(v.drive())
	m.print()
}
