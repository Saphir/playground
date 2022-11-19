package v2

type Director struct {
	builder iBuilder
}

func (d *Director) set_builder(builder string) {
	switch builder {
	case "porsche":
		d.builder = &PorscheBuilder{}
	case "bmw":
		d.builder = &BmwBuilder{}
	}
}

func (d *Director) get_car() interface{} {
	return d.builder.get_car()
}