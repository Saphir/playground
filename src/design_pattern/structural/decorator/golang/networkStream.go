package deco

type networkStream struct {
	stream iStream
}

func NewNetworkStream() *networkStream {
	return &networkStream{}
}
