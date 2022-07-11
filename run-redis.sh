#!/bin/sh
docker-compose --file docker-compose.yml up --detach --scale redis-master=1 --scale redis-secondary=2 --remove-orphans
