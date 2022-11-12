package v2

import "fmt"

type Porsche struct {
    Car
	carType string
}

func (p *Porsche) drive() string {
	return fmt.Sprintf("%s is driving a Porsche %s at %f km/h.", p.owner, p.carType, p.speed)
}