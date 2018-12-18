FROM alpine

RUN apk add --no-cache git bash cmake gcc make g++ \
    && git clone https://github.com/catchorg/Catch2.git \
    && cd Catch2 \
    && cmake -Bbuild -H. -DBUILD_TESTING=OFF \
    && cmake --build build/ --target install \
    && cd .. \
    && git clone -b master https://drvirens:New!!York123@gitlab.com/drvirens/zircon-microservice-petsitter-reg.git zircon \
    && cd zircon \
    && cd zcPetSitterRegistration \
    && mkdir b \
    && cd b \
    && cmake .. \
    && cmake --build . \
    && make install \
    && echo "virenbhaidone <------------" \
    && echo "OK. SUCCESS! meow"

CMD ["cmake", "--version"]
CMD ["/usr/local/zc/zc_bin/zcShared_TestLib", ""]
CMD ["/usr/local/zc/zc_bin/zcDomain_TestLib", ""]