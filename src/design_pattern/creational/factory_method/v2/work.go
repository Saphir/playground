package v2

import (
	"fmt"
)

func Work() {
	v, err := generateCar("Porsche", "Hans", 330.0); if err != nil {
		panic(err)
	}
	fmt.Println(v.drive())
}
