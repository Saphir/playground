package visitor

type IVisitor interface {
	visit(IComponent)
}

type Bmw struct {
}
func (b *Bmw) visit(component IComponent) {
	switch component.(type) {
	case *Door:
		println("BMW", component.Name())
	case *Wheel:
		println("BMW", component.Name())
	default:
		println("BMW unknown")
	}
}

type Audi struct {
}
func (a *Audi) visit(component IComponent) {
	switch component.(type) {
	case *Door:
		println("Audi", component.Name())
	case *Wheel:
		println("Audi", component.Name())
	default:
		println("Audi unknown")
	}
}
