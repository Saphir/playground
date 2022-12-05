package deco

type iStream interface {
	Read() string
	Write(data string)
	Seek(position int, origin int)
}

type stream struct {
	data string
}

func (s *stream) Read() string {
	return s.data
}

func (s *stream) Write(data string) {
	s.data = data
}

func (s *stream) Seek(position int, origin int) {
	// ...
}
