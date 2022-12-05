package deco

type fileStream struct {
	stream
}

func NewFileStream() *fileStream {
	return &fileStream{}
}
