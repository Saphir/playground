package v3

import "fmt"

func getCarFactory(carType string) (iCarFactory, error) {
	switch carType {
	case "Porsche":
		return &PorscheFactory{}, nil
	default:
		return nil, fmt.Errorf("unknown car type: %s", carType)
	}
}

type PorscheFactory struct {
}

func (f *PorscheFactory) generateCar(owner string, speed float32) (iCar, error) {
	return &Porsche{Car{owner, speed}, "911"}, nil
}
func (f *PorscheFactory) generateManual() (iManual, error) {
	return &PorscheManual{}, nil
}