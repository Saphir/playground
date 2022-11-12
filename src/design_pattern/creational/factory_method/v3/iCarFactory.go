package v3

type iCarFactory interface {
	generateCar(owner string, speed float32) (iCar, error)
	generateManual() (iManual, error)
}
