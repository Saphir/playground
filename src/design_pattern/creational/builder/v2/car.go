package v2

import "fmt"

type iCar interface {
	set_body()
	set_wheel()
	set_door()
	set_front_seat()
}

type Car struct {
	Body      string
	Wheel     string
	Door      string
	FrontSeat string
}

func (c *Car) set_body() {
	fmt.Println("Car set_body")
}

func (c *Car) set_wheel() {
}

func (c *Car) set_door() {
}

func (c *Car) set_front_seat() {
}

