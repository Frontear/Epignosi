import java.io.DataInputStream

@ExperimentalUnsignedTypes
fun main() {
    val stream = DataInputStream(Thread.currentThread().contextClassLoader.getResourceAsStream("HelloWorld.class")!!)

    println((stream.readInt().toUInt()).toString(16)) // magic

    println(stream.readUnsignedShort()) // minor_version
    println(stream.readUnsignedShort()) // major_version

    val constant_pool_count = stream.readUnsignedShort();
    println(constant_pool_count)

    // ...
}