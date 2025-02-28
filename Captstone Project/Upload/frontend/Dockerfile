#Dockerfile for React application
FROM docker.repository.esi.adp.com/clientcentral/node:12.7.0

WORKDIR /app/
COPY public/ /app/public
COPY src/ /app/src
COPY package.json /app/
#installs all the dependencies specified in the package.json
COPY .npmrc /app/
RUN npm install
CMD ["npm", "start"]