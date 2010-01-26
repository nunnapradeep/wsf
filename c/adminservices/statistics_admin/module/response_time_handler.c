/*
 * Copyright 2004,2005 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <axis2_handler_desc.h>
#include <axis2_op.h>
#include <axis2_msg_ctx.h>
#include <axutil_property.h>
#include <axis2_op.h>
#include "../axis2_counter.h"
#include "../axis2_statistics_admin_constants.h"

static axis2_status_t AXIS2_CALL
axis2_statistics_admin_calculate_response_times( 
                        const axutil_env_t *env,
                        struct axis2_msg_ctx *msg_ctx);

axis2_status_t AXIS2_CALL
axis2_statistics_admin_response_time_handler_invoke(
        struct axis2_handler *handler, 
        const axutil_env_t *env,
        struct axis2_msg_ctx *msg_ctx);


AXIS2_EXTERN axis2_handler_t* AXIS2_CALL
axis2_statistics_admin_response_time_handler_create(
        const axutil_env_t *env, 
        axutil_qname_t *qname) 
{
    axis2_handler_t *handler = NULL;
    
    handler = axis2_handler_create(env);
    if (!handler)
    {
        return NULL;
    }
   
    /* Handler init is handled by conf loading, so no need to do it here */
    
    /* Set the base struct's invoke op */
	axis2_handler_set_invoke(handler, env, axis2_statistics_admin_response_time_handler_invoke);

    return handler;
}

axis2_status_t AXIS2_CALL
axis2_statistics_admin_response_time_handler_invoke(struct axis2_handler *handler, 
                        const axutil_env_t *env,
                        struct axis2_msg_ctx *msg_ctx)
{
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_svc_t *svc = NULL;
    
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[adminservices] Start:axis2_statistics_admin_response_time_handler_invoke");
    AXIS2_PARAM_CHECK(env->error, msg_ctx, AXIS2_FAILURE);

    svc = axis2_msg_ctx_get_svc(msg_ctx, env);
    if(svc)
    {
        status = axis2_statistics_admin_calculate_response_times(env, msg_ctx);
    }
        
    AXIS2_LOG_TRACE(env->log, AXIS2_LOG_SI, "[adminservices] End:axis2_statistics_admin_response_time_handler_invoke");
    
    return status;
}


static axis2_status_t AXIS2_CALL
axis2_statistics_admin_calculate_response_times( 
                        const axutil_env_t *env,
                        struct axis2_msg_ctx *msg_ctx)
{
    axis2_status_t status = AXIS2_SUCCESS;
    axis2_counter_t *counter = NULL;
    axutil_param_t *param = NULL;

}
