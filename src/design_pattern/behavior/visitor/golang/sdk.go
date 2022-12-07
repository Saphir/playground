package visitor

type Sdk struct {
	rates []Rate
}

func NewSdk() *Sdk {
	sdk := &Sdk{}
	sdk.rates = []Rate{
		Rate{&Doller2Rmb{}},
		Rate{&Doller2Euro{}},
		Rate{&Doller2Yen{}},
	}
	return sdk
}

func (s *Sdk) Accept(visitor* Visitor) {
    for _, rate := range s.rates {
		rate.accept(visitor)
	}
}
