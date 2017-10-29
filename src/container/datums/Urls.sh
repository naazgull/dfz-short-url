
curl -i http://${1}:${2}/${3}_urls \
     -X PUT
curl -i http://${1}:${2}/${3}_urls/_index \
     -X POST \
     -H 'Content-Type: application/json' \
     -d "{\"type\":\"json\",\"index\":{ \"fields\" : [ \"method\" ] } }"
curl -i http://${1}:${2}/${3}_urls/_index \
     -X POST \
     -H 'Content-Type: application/json' \
     -d "{\"type\":\"json\",\"index\":{ \"fields\" : [ \"params\" ] } }"
curl -i http://${1}:${2}/${3}_urls/_index \
     -X POST \
     -H 'Content-Type: application/json' \
     -d "{\"type\":\"json\",\"index\":{ \"fields\" : [ \"id\" ] } }"
curl -i http://${1}:${2}/${3}_urls/_index \
     -X POST \
     -H 'Content-Type: application/json' \
     -d "{\"type\":\"json\",\"index\":{ \"fields\" : [ \"href\" ] } }"
curl -i http://${1}:${2}/${3}_urls/_index \
     -X POST \
     -H 'Content-Type: application/json' \
     -d "{\"type\":\"json\",\"index\":{ \"fields\" : [ \"created\" ] } }"
curl -i http://${1}:${2}/${3}_urls/_index \
     -X POST \
     -H 'Content-Type: application/json' \
     -d "{\"type\":\"json\",\"index\":{ \"fields\" : [ \"updated\" ] } }"



