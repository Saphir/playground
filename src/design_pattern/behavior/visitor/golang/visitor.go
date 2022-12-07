package visitor

type IVisitor interface {
	visit(r* Rate)
}

type Visitor struct {
	v IVisitor
}

func (v *Visitor) Visit(r* Rate) {
	v.v.visit(r)
}