package v2

import "fmt"

func generateCar(carType string, owner string, speed float32) (iCar, error) {
	switch carType {
	case "Porsche":
		return &Porsche{
					Car: Car{
						owner: owner,
						speed: speed,
					},
					carType: "911",
				}, nil
	default:
		return nil, fmt.Errorf("unknown car type: %s", carType)
	}
}