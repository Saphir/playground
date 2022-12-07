package visitor

type Sdk struct {
	visitor IVisitor
	components []IComponent
}

func NewSdk() *Sdk {
	sdk := &Sdk{}
	sdk.components = []IComponent{
		&Door{component{"door"}},
		&Wheel{component{"wheel"}},
	}
	return sdk
}

func (s *Sdk) Accept(visitor IVisitor) {
	s.visitor = visitor
    for _, component := range s.components {
		component.accept(visitor)
	}
}
