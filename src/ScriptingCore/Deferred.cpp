/**********************************************************\ 
Original Author: Richard Bateman (taxilian)

Created:    Feb 10, 2015
License:    Dual license model; choose one of two:
            New BSD License
            http://www.opensource.org/licenses/bsd-license.php
            - or -
            GNU Lesser General Public License, version 2.1
            http://www.gnu.org/licenses/lgpl-2.1.html

Copyright 2015 Richard Bateman and the FireBreath Dev Team
\**********************************************************/

#include "APITypes.h"
#include "Deferred.h"

using namespace FB;

Promise<void> FB::Deferred<void>::promise() const {
    return Promise<void>(m_data);
}

void FB::Deferred<void>::invalidate() const {
    if (m_data->state == PromiseState::PENDING) {
        reject(std::runtime_error("Deferred object destroyed"));
    }
}

void FB::Deferred<void>::resolve(Promise<void> v) const {
    auto self(*this);
    auto onDone = [self]() {
        self.resolve();
    };
    auto onFail = [self](std::exception e) { self.reject(e); };
    promise().done(onDone, onFail);
}
