class Stream(object):
    def __init__(self):
        pass

    def Read(self, length) -> bytes:
        pass
    
    def Seek(self, position: int, origin: int):
        pass

    def Write(self, data: bytes):
        pass

class FileStream(Stream):
    def __init__(self):
        super().__init__()

class MemoryStream(Stream):
    def __init__(self):
        super().__init__()

class NetworkStream(Stream):
    def __init__(self):
        super().__init__()

class EncryptionFileStream(FileStream):
    def __init__(self):
        super().__init__()
    
    def Read(self, length) -> bytes:
        data = super().Read(length)
        return self.Decrypt(data)

    def Write(self, data: bytes):
        data = self.Encrypt(data)
        super().Write(data)

    def Encrypt(self, data: bytes) -> bytes:
        print('[FileStream] Encrypting data...')
        return data

    def Decrypt(self, data: bytes) -> bytes:
        print('[FileStream] Decrypting data...')
        return data

class CompressionFileStream(FileStream):
    def __init__(self):
        super().__init__()
    
    def Read(self, length) -> bytes:
        data = super().Read(length)
        return self.Decompress(data)

    def Write(self, data: bytes):
        data = self.Compress(data)
        super().Write(data)

    def Compress(self, data: bytes) -> bytes:
        print('[FileStream] Compressing data...')
        return data

    def Decompress(self, data: bytes) -> bytes:
        print('[FileStream] Decompressing data...')
        return data

class EncryptionCompressionFileStream(EncryptionFileStream, CompressionFileStream):
    def __init__(self):
        super().__init__()

class EncryptionMemoryStream(MemoryStream):
    def __init__(self):
        super().__init__()
    
    def Read(self, length) -> bytes:
        data = super().Read(length)
        return self.Decrypt(data)

    def Write(self, data: bytes):
        data = self.Encrypt(data)
        super().Write(data)

    def Encrypt(self, data: bytes) -> bytes:
        print('[MemoryStream] Encrypting data...')
        return data

    def Decrypt(self, data: bytes) -> bytes:
        print('[MemoryStream] Decrypting data...')
        return data

class CompressionMemoryStream(MemoryStream):
    def __init__(self):
        super().__init__()
    
    def Read(self,length) -> bytes:
        data = super().Read(length)
        return self.Decompress(data)

    def Write(self, data: bytes):
        data = self.Compress(data)
        super().Write(data)

    def Compress(self, data: bytes) -> bytes:
        print('[MemoryStream] Compressing data...')
        return data

    def Decompress(self, data: bytes) -> bytes:
        print('[MemoryStream] Decompressing data...')
        return data

def Work():
    encryption_compression_stream = EncryptionCompressionFileStream()
    encryption_compression_stream.Write(b'Hello, world!')
    encryption_compression_stream.Read(1024)
