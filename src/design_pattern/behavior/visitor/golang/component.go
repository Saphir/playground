package visitor

type IComponent interface {
	accept(visitor IVisitor)
	Name() string
}

type component struct {
	name string
}
func (c *component) Name() string {
	return c.name
}

type Door struct {
	component
}

func (d *Door) accept(visitor IVisitor) {
	visitor.visit(d)
}

type Wheel struct {
	component
}

func (w *Wheel) accept(visitor IVisitor) {
	visitor.visit(w)
}
