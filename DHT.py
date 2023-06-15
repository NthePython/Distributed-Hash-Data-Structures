import opendht as dht

node = dht.DhtRunner()
node.run()
node.bootstrap("bootstrap.jami.net", "4222")
node.put(dht.InfoHash.get("unique_key"), dht.Value(b'some binary data'))
results = node.get(dht.InfoHash.get("unique_key"))
