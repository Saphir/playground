package v3

import "fmt"

type Porsche struct {
    Car
	carType string
}

type PorscheManual struct {
}

func (p *Porsche) drive() string {
	return fmt.Sprintf("%s is driving a Porsche %s at %f km/h.", p.owner, p.carType, p.speed)
}

func (p *PorscheManual) print() {
	fmt.Println("This is a Porsche manual.")
}