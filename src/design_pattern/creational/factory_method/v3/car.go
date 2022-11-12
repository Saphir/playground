package v3

import "fmt"

type Car struct {
	owner string
	speed float32
}

func (c *Car) drive() string {
	return fmt.Sprintf("%s is driving a Car at %f km/h.", c.owner, c.speed)
}
