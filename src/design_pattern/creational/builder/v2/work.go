package v2

import (
	"fmt"
)

func Work() {
	director := &Director{}

	director.set_builder("porsche")
	porsche := director.get_car()
	fmt.Println(porsche)

	director.set_builder("bmw")
	bmw := director.get_car()
	fmt.Println(bmw)
}