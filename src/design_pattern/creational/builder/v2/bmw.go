package v2


type Bmw struct {
	Car
	RearSeat string
}

func (b *Bmw) set_body() {
	b.Body = "Bmw Body"
}

func (b *Bmw) set_wheel() {
	b.Wheel = "Bmw Wheel"
}

func (b *Bmw) set_door() {
	b.Door = "Bmw Door"
}

func (b *Bmw) set_front_seat() {
	b.FrontSeat = "Bmw FrontSeat"
}

func (b *Bmw) set_rear_seat() {
	b.RearSeat = "Bmw RearSeat"
}