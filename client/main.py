import socket
import block_device_event_pb2


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client:
    client.connect(("localhost", 8080))

    while True:
        data = client.recv(1024)

        event = block_device_event_pb2.BlockDeviceEvent()
        event.ParseFromString(data)

        print(f"Received Protobuf Event: Action={block_device_event_pb2.BlockDeviceEventAction.Name(event.action)}, Devname={event.devname}, Vendor={event.vendor}, Model={event.model}, Size={event.size}, Partitions={event.partitions}, Type={block_device_event_pb2.BlockDeviceType.Name(event.type) if event.type is not None else event.type}")
