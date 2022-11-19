package v2

type iBuilder interface {
	get_car() interface{}
}

type PorscheBuilder struct {
}

func (p *PorscheBuilder) get_car() interface{} {
	car := &Porsche{}
	car.set_body()
	car.set_wheel()
	car.set_door()
	car.set_front_seat()
	car.set_gps()
	return car
}

type BmwBuilder struct {
}

func (b *BmwBuilder) get_car() interface{} {
	car := &Bmw{}
	car.set_body()
	car.set_wheel()
	car.set_door()
	car.set_front_seat()
	car.set_rear_seat()
	return car
}

