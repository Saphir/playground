package v2

type Porsche struct {
	Car
	Gps string
}

func (p *Porsche) set_body() {
	p.Car.Body = "Porsche Body"
}

func (p *Porsche) set_wheel() {
	p.Car.Wheel = "Porsche Wheel"
}

func (p *Porsche) set_door() {
	p.Car.Door = "Porsche Door"
}

func (p *Porsche) set_front_seat() {
	p.Car.FrontSeat = "Porsche FrontSeat"
}

func (p *Porsche) set_gps() {
	p.Gps = "Porsche Gps"
}