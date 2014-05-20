/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima RTPS is licensed to you under the terms described in the
 * EPROSIMARTPS_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file DiscoveredData.cpp
 *
 *  Created on: May 19, 2014
 *      Author: Gonzalo Rodriguez Canosa
 *      email:  gonzalorodriguez@eprosima.com
 *              grcanosa@gmail.com  	
 */


#include "eprosimartps/discovery/data/DiscoveredData.h"
#include "eprosimartps/discovery/data/DiscoveredWriterData.h"
#include "eprosimartps/discovery/data/DiscoveredReaderData.h"
#include "eprosimartps/discovery/data/DiscoveredTopicData.h"
#include "eprosimartps/discovery/data/DiscoveredParticipantData.h"

namespace eprosima{

namespace rtps{

bool DiscoveredData::ParameterList2DiscoveredWriterData(ParameterList_t& param, DiscoveredWriterData* wdata)
{
	for(std::vector<Parameter_t*>::iterator it = param.m_parameters.begin();
			it!=param.m_parameters.end();++it)
	{
		switch((*it)->Pid)
		{
		case PID_DURABILITY:
		{
			DurabilityQosPolicy * p = (DurabilityQosPolicy*)(*it);
			wdata->m_durability = *p;
			break;
		}
		case PID_DURABILITY_SERVICE:
		{
			DurabilityServiceQosPolicy * p = (DurabilityServiceQosPolicy*)(*it);
			wdata->m_durabilityService = *p;
			break;
		}
		case PID_DEADLINE:
		{
			DeadlineQosPolicy * p = (DeadlineQosPolicy*)(*it);
			wdata->m_deadline = *p;
			break;
		}
		case PID_LATENCY_BUDGET:
		{
			LatencyBudgetQosPolicy * p = (LatencyBudgetQosPolicy*)(*it);
			wdata->m_latencyBudget = *p;
			break;
		}
		case PID_LIVELINESS:
		{
			LivelinessQosPolicy * p = (LivelinessQosPolicy*)(*it);
			wdata->m_liveliness = *p;
			break;
		}
		case PID_RELIABILITY:
		{
			ReliabilityQosPolicy * p = (ReliabilityQosPolicy*)(*it);
			wdata->m_reliability = *p;
			break;
		}
		case PID_LIFESPAN:
		{

			LifespanQosPolicy * p = (LifespanQosPolicy*)(*it);
			wdata->m_lifespan = *p;
			break;
		}
		case PID_USER_DATA:
		{
			UserDataQosPolicy * p = (UserDataQosPolicy*)(*it);
			wdata->m_userData = *p;
			break;
		}
		case PID_TIME_BASED_FILTER:
		{
			TimeBasedFilterQosPolicy * p = (TimeBasedFilterQosPolicy*)(*it);
			wdata->m_timeBasedFilter = *p;
			break;
		}
		case PID_OWNERSHIP:
		{
			OwnershipQosPolicy * p = (OwnershipQosPolicy*)(*it);
			wdata->m_ownership = *p;
			break;
		}
		case PID_OWNERSHIP_STRENGTH:
		{
			OwnershipStrengthQosPolicy * p = (OwnershipStrengthQosPolicy*)(*it);
			wdata->m_ownershipStrength = *p;
			break;
		}
		case PID_DESTINATION_ORDER:
		{
			DestinationOrderQosPolicy * p = (DestinationOrderQosPolicy*)(*it);
			wdata->m_destinationOrder = *p;
			break;
		}

		case PID_PRESENTATION:
		{
			PresentationQosPolicy * p = (PresentationQosPolicy*)(*it);
			wdata->m_presentation = *p;
			break;
		}
		case PID_PARTITION:
		{
			PartitionQosPolicy * p = (PartitionQosPolicy*)(*it);
			wdata->m_partition = *p;
			break;
		}
		case PID_TOPIC_DATA:
		{
			TopicDataQosPolicy * p = (TopicDataQosPolicy*)(*it);
			wdata->m_topicData = *p;
			break;
		}
		case PID_GROUP_DATA:
		{

			GroupDataQosPolicy * p = (GroupDataQosPolicy*)(*it);
			wdata->m_groupData = *p;
			break;
		}
		case PID_TOPIC_NAME:
		{
			ParameterString_t*p = (ParameterString_t*)(*it);
			wdata->m_topicName = p->m_string;
			break;
		}
		case PID_TYPE_NAME:
		{
			ParameterString_t*p = (ParameterString_t*)(*it);
			wdata->m_typeName = p->m_string;
			break;
		}
		case PID_PARTICIPANT_GUID:
		{
			ParameterGuid_t * p = (ParameterGuid_t*)(*it);
			for(uint8_t i =0;i<16;++i)
			{
				if(i<12)
					wdata->m_participantKey.value[i] = p->guid.guidPrefix.value[i];
				else
					wdata->m_participantKey.value[i] = p->guid.entityId.value[i];
			}
			break;
		}
		case PID_UNICAST_LOCATOR:
		{
			ParameterLocator_t* p = (ParameterLocator_t*)(*it);
			wdata->m_writerProxy.unicastLocatorList.push_back(p->locator);
			break;
		}
		case PID_MULTICAST_LOCATOR:
		{
			ParameterLocator_t* p = (ParameterLocator_t*)(*it);
			wdata->m_writerProxy.multicastLocatorList.push_back(p->locator);
			break;
		}
		default:
			break;
		}
	}
	return true;
}

bool DiscoveredData::ParameterList2DiscoveredReaderData(ParameterList_t& param, DiscoveredReaderData* rdata)
{
	for(std::vector<Parameter_t*>::iterator it = param.m_parameters.begin();
			it!=param.m_parameters.end();++it)
	{
		switch((*it)->Pid)
		{
		case PID_DURABILITY:
		{
			DurabilityQosPolicy * p = (DurabilityQosPolicy*)(*it);
			rdata->m_durability = *p;
			break;
		}
		case PID_DURABILITY_SERVICE:
		{
			DurabilityServiceQosPolicy * p = (DurabilityServiceQosPolicy*)(*it);
			rdata->m_durabilityService = *p;
			break;
		}
		case PID_DEADLINE:
		{
			DeadlineQosPolicy * p = (DeadlineQosPolicy*)(*it);
			rdata->m_deadline = *p;
			break;
		}
		case PID_LATENCY_BUDGET:
		{
			LatencyBudgetQosPolicy * p = (LatencyBudgetQosPolicy*)(*it);
			rdata->m_latencyBudget = *p;
			break;
		}
		case PID_LIVELINESS:
		{
			LivelinessQosPolicy * p = (LivelinessQosPolicy*)(*it);
			rdata->m_liveliness = *p;
			break;
		}
		case PID_RELIABILITY:
		{
			ReliabilityQosPolicy * p = (ReliabilityQosPolicy*)(*it);
			rdata->m_reliability = *p;
			break;
		}
		case PID_LIFESPAN:
		{

			LifespanQosPolicy * p = (LifespanQosPolicy*)(*it);
			rdata->m_lifespan = *p;
			break;
		}
		case PID_USER_DATA:
		{
			UserDataQosPolicy * p = (UserDataQosPolicy*)(*it);
			rdata->m_userData = *p;
			break;
		}
		case PID_TIME_BASED_FILTER:
		{
			TimeBasedFilterQosPolicy * p = (TimeBasedFilterQosPolicy*)(*it);
			rdata->m_timeBasedFilter = *p;
			break;
		}
		case PID_OWNERSHIP:
		{
			OwnershipQosPolicy * p = (OwnershipQosPolicy*)(*it);
			rdata->m_ownership = *p;
			break;
		}
		case PID_DESTINATION_ORDER:
		{
			DestinationOrderQosPolicy * p = (DestinationOrderQosPolicy*)(*it);
			rdata->m_destinationOrder = *p;
			break;
		}

		case PID_PRESENTATION:
		{
			PresentationQosPolicy * p = (PresentationQosPolicy*)(*it);
			rdata->m_presentation = *p;
			break;
		}
		case PID_PARTITION:
		{
			PartitionQosPolicy * p = (PartitionQosPolicy*)(*it);
			rdata->m_partition = *p;
			break;
		}
		case PID_TOPIC_DATA:
		{
			TopicDataQosPolicy * p = (TopicDataQosPolicy*)(*it);
			rdata->m_topicData = *p;
			break;
		}
		case PID_GROUP_DATA:
		{

			GroupDataQosPolicy * p = (GroupDataQosPolicy*)(*it);
			rdata->m_groupData = *p;
			break;
		}
		case PID_TOPIC_NAME:
		{
			ParameterString_t*p = (ParameterString_t*)(*it);
			rdata->m_topicName = p->m_string;
			break;
		}
		case PID_TYPE_NAME:
		{
			ParameterString_t*p = (ParameterString_t*)(*it);
			rdata->m_typeName = p->m_string;
			break;
		}
		case PID_PARTICIPANT_GUID:
		{
			ParameterGuid_t * p = (ParameterGuid_t*)(*it);
			for(uint8_t i =0;i<16;++i)
			{
				if(i<12)
					rdata->m_participantKey.value[i] = p->guid.guidPrefix.value[i];
				else
					rdata->m_participantKey.value[i] = p->guid.entityId.value[i];
			}
			break;
		}
		case PID_UNICAST_LOCATOR:
		{
			ParameterLocator_t* p = (ParameterLocator_t*)(*it);
			rdata->m_readerProxy.unicastLocatorList.push_back(p->locator);
			break;
		}
		case PID_MULTICAST_LOCATOR:
		{
			ParameterLocator_t* p = (ParameterLocator_t*)(*it);
			rdata->m_readerProxy.multicastLocatorList.push_back(p->locator);
			break;
		}
		case PID_EXPECTS_INLINE_QOS:
		{
			ParameterBool_t*p =(ParameterBool_t*)(*it);
			rdata->m_readerProxy.expectsInlineQos = p->value;
			break;
		}
		default:
			break;
		}
	}
	return true;

}


bool DiscoveredData::ParameterList2DiscoveredTopicData(ParameterList_t& param, DiscoveredTopicData* tdata)
{
	for(std::vector<Parameter_t*>::iterator it = param.m_parameters.begin();
			it!=param.m_parameters.end();++it)
	{
		switch((*it)->Pid)
		{
		case PID_DURABILITY:
		{
			DurabilityQosPolicy * p = (DurabilityQosPolicy*)(*it);
			tdata->m_durability = *p;
			break;
		}
		case PID_DEADLINE:
		{
			DeadlineQosPolicy * p = (DeadlineQosPolicy*)(*it);
			tdata->m_deadline = *p;
			break;
		}
		case PID_LATENCY_BUDGET:
		{
			LatencyBudgetQosPolicy * p = (LatencyBudgetQosPolicy*)(*it);
			tdata->m_latencyBudget = *p;
			break;
		}
		case PID_LIVELINESS:
		{
			LivelinessQosPolicy * p = (LivelinessQosPolicy*)(*it);
			tdata->m_liveliness = *p;
			break;
		}
		case PID_RELIABILITY:
		{
			ReliabilityQosPolicy * p = (ReliabilityQosPolicy*)(*it);
			tdata->m_reliability = *p;
			break;
		}
		case PID_TRANSPORT_PRIORITY:
		{
			TransportPriorityQosPolicy * p = (TransportPriorityQosPolicy*)(*it);
			tdata->m_transportPriority = *p;
			break;
		}
		case PID_LIFESPAN:
		{
			LifespanQosPolicy * p = (LifespanQosPolicy*)(*it);
			tdata->m_lifespan = *p;
			break;
		}
		case PID_OWNERSHIP:
		{
			OwnershipQosPolicy * p = (OwnershipQosPolicy*)(*it);
			tdata->m_ownership = *p;
			break;
		}
		case PID_DESTINATION_ORDER:
		{
			DestinationOrderQosPolicy * p = (DestinationOrderQosPolicy*)(*it);
			tdata->m_destinationOrder = *p;
			break;
		}
		case PID_HISTORY:
		{
			HistoryQosPolicy* p = (HistoryQosPolicy*)(*it);
			tdata->m_history = *p;
			break;
		}
		case PID_RESOURCE_LIMITS:
		{
			ResourceLimitsQosPolicy* p = (ResourceLimitsQosPolicy*)(*it);
			tdata->m_resourceLimits = *p;
			break;
		}
		case PID_PRESENTATION:
		{
			PresentationQosPolicy * p = (PresentationQosPolicy*)(*it);
			tdata->m_presentation = *p;
			break;
		}
		case PID_TOPIC_DATA:
		{
			TopicDataQosPolicy * p = (TopicDataQosPolicy*)(*it);
			tdata->m_topicData = *p;
			break;
		}
		case PID_TOPIC_NAME:
		{
			ParameterString_t*p = (ParameterString_t*)(*it);
			tdata->m_topicName = p->m_string;
			break;
		}
		case PID_TYPE_NAME:
		{
			ParameterString_t*p = (ParameterString_t*)(*it);
			tdata->m_typeName = p->m_string;
			break;
		}

		default:
			break;
		}
	}
	return true;
}

bool DiscoveredData::DiscoveredWriterData2ParameterList(DiscoveredWriterData& wdata, ParameterList_t* param)
{
	for(LocatorListIterator lit = wdata.m_writerProxy.unicastLocatorList.begin();
			lit!=wdata.m_writerProxy.unicastLocatorList.end();++lit)
	{
		ParameterLocator_t* p = new ParameterLocator_t(PID_UNICAST_LOCATOR,PARAMETER_LOCATOR_LENGTH,*lit);
		param->m_parameters.push_back(p);
	}
	for(LocatorListIterator lit = wdata.m_writerProxy.multicastLocatorList.begin();
			lit!=wdata.m_writerProxy.multicastLocatorList.end();++lit)
	{
		ParameterLocator_t* p = new ParameterLocator_t(PID_MULTICAST_LOCATOR,PARAMETER_LOCATOR_LENGTH,*lit);
		param->m_parameters.push_back(p);
	}
	{
		ParameterGuid_t* p = new ParameterGuid_t(PID_PARTICIPANT_GUID,PARAMETER_GUID_LENGTH,wdata.m_participantKey);
		param->m_parameters.push_back(p);
	}
	{
		ParameterString_t * p = new ParameterString_t(PID_TOPIC_NAME,0,wdata.m_topicName);
		param->m_parameters.push_back(p);
	}
	{
		ParameterString_t * p = new ParameterString_t(PID_TYPE_NAME,0,wdata.m_typeName);
		param->m_parameters.push_back(p);
	}
	{
		ParameterString_t * p = new ParameterString_t(PID_TOPIC_NAME,0,wdata.m_topicName);
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_durability.isDefault)
	{
		DurabilityQosPolicy*p = new DurabilityQosPolicy();
		*p = wdata.m_durability;
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_durabilityService.isDefault)
	{
		DurabilityServiceQosPolicy*p = new DurabilityServiceQosPolicy();
		*p = wdata.m_durabilityService;
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_deadline.isDefault)
	{
		DeadlineQosPolicy*p = new DeadlineQosPolicy();
		*p = wdata.m_deadline;
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_latencyBudget.isDefault)
	{
		LatencyBudgetQosPolicy*p = new LatencyBudgetQosPolicy();
		*p = wdata.m_latencyBudget;
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_liveliness.isDefault)
	{
		LivelinessQosPolicy*p = new LivelinessQosPolicy();
		*p = wdata.m_liveliness;
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_reliability.isDefault)
	{
		ReliabilityQosPolicy*p = new ReliabilityQosPolicy();
		*p = wdata.m_reliability;
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_lifespan.isDefault)
	{
		LifespanQosPolicy*p = new LifespanQosPolicy();
		*p = wdata.m_lifespan;
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_userData.isDefault)
	{
		UserDataQosPolicy*p = new UserDataQosPolicy();
		*p = wdata.m_userData;
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_timeBasedFilter.isDefault)
	{
		TimeBasedFilterQosPolicy*p = new TimeBasedFilterQosPolicy();
		*p = wdata.m_timeBasedFilter;
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_ownership.isDefault)
	{
		OwnershipQosPolicy*p = new OwnershipQosPolicy();
		*p = wdata.m_ownership;
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_ownershipStrength.isDefault)
	{
		OwnershipStrengthQosPolicy*p = new OwnershipStrengthQosPolicy();
		*p = wdata.m_ownershipStrength;
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_destinationOrder.isDefault)
	{
		DestinationOrderQosPolicy*p = new DestinationOrderQosPolicy();
		*p = wdata.m_destinationOrder;
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_presentation.isDefault)
	{
		PresentationQosPolicy*p = new PresentationQosPolicy();
		*p = wdata.m_presentation;
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_partition.isDefault)
	{
		PartitionQosPolicy*p = new PartitionQosPolicy();
		*p = wdata.m_partition;
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_topicData.isDefault)
	{
		TopicDataQosPolicy*p = new TopicDataQosPolicy();
		*p = wdata.m_topicData;
		param->m_parameters.push_back(p);
	}
	if(!wdata.m_groupData.isDefault)
	{
		GroupDataQosPolicy*p = new GroupDataQosPolicy();
		*p = wdata.m_groupData;
		param->m_parameters.push_back(p);
	}
	return true;
}

bool DiscoveredData::DiscoveredReaderData2ParameterList(DiscoveredReaderData& rdata, ParameterList_t* param)
{
	for(LocatorListIterator lit = rdata.m_readerProxy.unicastLocatorList.begin();
			lit!=rdata.m_readerProxy.unicastLocatorList.end();++lit)
	{
		ParameterLocator_t* p = new ParameterLocator_t(PID_UNICAST_LOCATOR,PARAMETER_LOCATOR_LENGTH,*lit);
		param->m_parameters.push_back(p);
	}
	for(LocatorListIterator lit = rdata.m_readerProxy.multicastLocatorList.begin();
			lit!=rdata.m_readerProxy.multicastLocatorList.end();++lit)
	{
		ParameterLocator_t* p = new ParameterLocator_t(PID_MULTICAST_LOCATOR,PARAMETER_LOCATOR_LENGTH,*lit);
		param->m_parameters.push_back(p);
	}
	{
		ParameterBool_t * p = new ParameterBool_t(PID_EXPECTS_INLINE_QOS,PARAMETER_BOOL_LENGTH,rdata.m_readerProxy.expectsInlineQos);
		param->m_parameters.push_back(p);
	}
	{
		ParameterGuid_t* p = new ParameterGuid_t(PID_PARTICIPANT_GUID,PARAMETER_GUID_LENGTH,rdata.m_participantKey);
		param->m_parameters.push_back(p);
	}
	{
		ParameterString_t * p = new ParameterString_t(PID_TOPIC_NAME,0,rdata.m_topicName);
		param->m_parameters.push_back(p);
	}
	{
		ParameterString_t * p = new ParameterString_t(PID_TYPE_NAME,0,rdata.m_typeName);
		param->m_parameters.push_back(p);
	}
	{
		ParameterString_t * p = new ParameterString_t(PID_TOPIC_NAME,0,rdata.m_topicName);
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_durability.isDefault)
	{
		DurabilityQosPolicy*p = new DurabilityQosPolicy();
		*p = rdata.m_durability;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_durabilityService.isDefault)
	{
		DurabilityServiceQosPolicy*p = new DurabilityServiceQosPolicy();
		*p = rdata.m_durabilityService;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_deadline.isDefault)
	{
		DeadlineQosPolicy*p = new DeadlineQosPolicy();
		*p = rdata.m_deadline;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_latencyBudget.isDefault)
	{
		LatencyBudgetQosPolicy*p = new LatencyBudgetQosPolicy();
		*p = rdata.m_latencyBudget;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_liveliness.isDefault)
	{
		LivelinessQosPolicy*p = new LivelinessQosPolicy();
		*p = rdata.m_liveliness;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_reliability.isDefault)
	{
		ReliabilityQosPolicy*p = new ReliabilityQosPolicy();
		*p = rdata.m_reliability;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_lifespan.isDefault)
	{
		LifespanQosPolicy*p = new LifespanQosPolicy();
		*p = rdata.m_lifespan;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_userData.isDefault)
	{
		UserDataQosPolicy*p = new UserDataQosPolicy();
		*p = rdata.m_userData;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_timeBasedFilter.isDefault)
	{
		TimeBasedFilterQosPolicy*p = new TimeBasedFilterQosPolicy();
		*p = rdata.m_timeBasedFilter;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_ownership.isDefault)
	{
		OwnershipQosPolicy*p = new OwnershipQosPolicy();
		*p = rdata.m_ownership;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_destinationOrder.isDefault)
	{
		DestinationOrderQosPolicy*p = new DestinationOrderQosPolicy();
		*p = rdata.m_destinationOrder;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_presentation.isDefault)
	{
		PresentationQosPolicy*p = new PresentationQosPolicy();
		*p = rdata.m_presentation;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_partition.isDefault)
	{
		PartitionQosPolicy*p = new PartitionQosPolicy();
		*p = rdata.m_partition;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_topicData.isDefault)
	{
		TopicDataQosPolicy*p = new TopicDataQosPolicy();
		*p = rdata.m_topicData;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_groupData.isDefault)
	{
		GroupDataQosPolicy*p = new GroupDataQosPolicy();
		*p = rdata.m_groupData;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_timeBasedFilter.isDefault)
	{
		TimeBasedFilterQosPolicy*p = new TimeBasedFilterQosPolicy();
		*p = rdata.m_timeBasedFilter;
		param->m_parameters.push_back(p);
	}
	if(!rdata.m_durabilityService.isDefault)
	{
		DurabilityServiceQosPolicy * p = new DurabilityServiceQosPolicy();
		*p = rdata.m_durabilityService;
		param->m_parameters.push_back(p);
	}
	return true;
}

bool DiscoveredData::DiscoveredTopicData2ParameterList(DiscoveredTopicData& tdata, ParameterList_t* param)
{
	pError("DiscoveredTopicData2ParameterList NOT YET IMPLEMENTED"<<endl);
	return true;
}

}
}

