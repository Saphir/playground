package visitor

type IRate interface {
	GetRate() float64
	Name() string
}

type Rate struct {
	r IRate
}

func (r *Rate) accept(v* Visitor) {
	v.Visit(r)
}

type Doller2Rmb struct {
}
func (d *Doller2Rmb) GetRate() float64 {
	return 6.98
}
func (d* Doller2Rmb) Name() string {
	return "Rmb"
}

type Doller2Euro struct {
}
func (d *Doller2Euro) GetRate() float64 {
	return 0.85
}
func (d* Doller2Euro) Name() string {
	return "Euro"
}

type Doller2Yen struct {
}
func (d *Doller2Yen) GetRate() float64 {
	return 137.98
}
func (d* Doller2Yen) Name() string {
	return "Yen"
}