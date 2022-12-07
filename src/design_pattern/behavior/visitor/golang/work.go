package visitor

func Work() {
	visitor_bmw := &Bmw{}
	visitor_audi := &Audi{}

	sdk := NewSdk()
	sdk.Accept(visitor_bmw)
	sdk.Accept(visitor_audi)
}
