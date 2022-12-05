package deco

import (
	"fmt"
)

func Work() {
	fmt.Println("Decorator pattern in Go")
	fileStream := NewFileStream()
	encriptStream := NewEncriptStream(fileStream)
	compressStream := NewCompressStream(encriptStream)
	compressStream.Write("Hello world")
	compressStream.Read()
}