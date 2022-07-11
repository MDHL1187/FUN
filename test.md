Installing docker-compose:
	1. sudo curl -L "https://github.com/docker/compose/releases/download/1.29.0/docker-compose-$(uname -s)-$(uname -m)" -o /usr/local/bin/docker-compose
	2. sudo chmod +x /usr/local/bin/docker-compose
	
Inspect docker image IP:
	1. sudo docker inspect --format='{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' redisCache
	2. sudo docker inspect --format='{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' redisCacheCommander
	
https://github.com/MicrosoftArchive/redis/releases