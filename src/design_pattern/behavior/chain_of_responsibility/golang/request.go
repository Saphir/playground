package chain_of_responsibility

type Request struct {
	Username string
	Password string
	IP       string
}

func NewRequest () *Request {
	return &Request{}
}
